#include "Obj2D.hlsli"

struct Material
{
    float4 color;
    float4x4 uvTransform;
};

ConstantBuffer<Material> gMaterial : register(b0);
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
    
    if (gMaterial.color.x < 1.0f)
    {
        output.color = float4(1, 0, 0, 1);
        return output;        
    }
    
    float4 transformdUV = mul(float4(input.texcood, 0.0f, 1.0f), gMaterial.uvTransform);
    
    //Texture��Sampling����
    float4 textureColor = gTexture.Sample(gSampler, transformdUV.xy);
    
    // Sampling����texture�̐F��material�̐F����Z���č��������Ă݂�
    output.color = gMaterial.color * textureColor;
    
    return output;
}