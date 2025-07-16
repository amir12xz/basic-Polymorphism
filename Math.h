#pragma once
template <typename Y>
Y sum(Y a, Y b)
{
	Y check;
	check = a + b;
	return check;
}
template <typename Y>
Y Power(Y a, int b,Y c=1)
{
	for (int i = 0; i < b; i++)
	{
		c = c * a;
	}
	return c;
}
float Exp(float x, int terms = 20)
{
    float result = 1.0f;   
    float power = 1.0f;
    float factorial = 1.0f;

    for (int i = 1; i < terms; i++)
    {
        power *= x;
        factorial *= i;
        result += power / factorial;
    }

    return result;
}
float sigmoid(float x)
{
    return 1.0f / (1.0f + Exp(-x));
}
float sigmoid_derivative(float x)
{
    float s = sigmoid(x);
    return s * (1.0f - s);
}
float relu(float x)
{
    return x > 0 ? x : 0;
}

float relu_derivative(float x)
{
    return x > 0 ? 1.0f : 0.0f;
}
float abs(float x)
{
    return x < 0 ? -x : x;
}

float max(float a, float b)
{
    return a > b ? a : b;
}
float tanh_func(float x)
{
    float ex = exp(x);
    float enx = exp(-x);
    return (ex - enx) / (ex + enx);
}


