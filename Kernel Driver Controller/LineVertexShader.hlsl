struct Input
{
    float2 position : POSITION;
    float4 color : COLOR;
};

struct Output
{
    float4 position : SV_POSITION;
    float4 color : COLOR;
};


Output main(Input input)
{
    Output output;
    output.position = float4(input.position, 0.0f, 1.0f);
    output.color = input.color;
    return output;
}
