Texture2D shaderTexture : register(t0);
SamplerState SampleType : register(s0);

cbuffer LightBuffer
{
	float4 diffuseColor;
	float3 lightDirection;
	float padding;
};

struct PixelInputType
{
	float4 position : SV_POSITION;
	float2 tex : TEXCOORD0;
	float3 normal : NORMAL;
};

float4 LightPixelShader(PixelInputType input) : SV_TARGET
{
	float4 textureColor;

	float4 lightColor;
	float3 lightDir;
	float lightIntensity;

	textureColor = shaderTexture.Sample(SampleType, input.tex);

	lightDir = -lightDirection;

	lightIntensity = saturate(dot(input.normal, lightDir));

	lightColor = saturate(diffuseColor * lightIntensity);

	lightColor = lightColor * textureColor;

	return lightColor;
}