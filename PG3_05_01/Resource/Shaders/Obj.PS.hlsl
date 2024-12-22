#include "Obj.hlsli"

struct Material
{
    float4 color;
    int enableLighting; // 0�̓��C�g�����A1�̓����o�[�g�A2�̓n�[�t�����o�[�g
    float4x4 uvTransform;
};

struct DirectionalLight
{
    float4 color; // ���C�g�̐F
    float3 direction; // ���C�g�̌���
    float intensity; // ���C�g�̖��邳(�P�x)
};

ConstantBuffer<Material> gMaterial : register(b0);
ConstantBuffer<DirectionalLight> gDirectionalLight : register(b1);
//SRV��register��t
Texture2D<float4> gTexture : register(t0);
// Sampler��register��s
SamplerState gSampler : register(s0);

struct PixlShaderOutput
{
    float4 color : SV_TARGET0;
};


PixlShaderOutput main(VertexShaderOutput input)
{
    PixlShaderOutput output;
    output.color = gMaterial.color;
    
    float4 transformdUV = mul(float4(input.texcood, 0.0f, 1.0f), gMaterial.uvTransform);
    
    //Texture��Sampling����
    float4 textureColor = gTexture.Sample(gSampler, transformdUV.xy);
    
    // Sampling����texture�̐F��material�̐F����Z���č��������Ă݂�
    output.color = gMaterial.color * textureColor;
    
    if (gMaterial.enableLighting == 1)
    { // Lighting����ꍇ
        
        /* Lambert */
        float cos = saturate(dot(normalize(input.normal), -gDirectionalLight.direction));
        output.color = gMaterial.color * textureColor * gDirectionalLight.color * cos * gDirectionalLight.intensity;
    }
    else if (gMaterial.enableLighting == 2)
    {
        /* Half Lambert */
        float NdotL = dot(normalize(input.normal), -gDirectionalLight.direction);
        float cos = pow(NdotL * 0.5f + 0.5f, 2.0f);
        output.color = gMaterial.color * textureColor * gDirectionalLight.color * cos * gDirectionalLight.intensity;
    }
    else
    { // Lighting���Ȃ��ꍇ�B�O��܂łƓ������Z
        output.color = gMaterial.color * textureColor;
    }
    
    return output;
}