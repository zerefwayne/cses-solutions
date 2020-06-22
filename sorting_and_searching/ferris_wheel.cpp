#include <bits/stdc++.h>

using namespace std;

void task()
{

    int numChildren;
    long int maxGondolaWeight;

    scanf("%d %ld", &numChildren, &maxGondolaWeight);

    long int children[numChildren];

    for (int i = 0; i < numChildren; i++)
    {
        scanf("%ld", &children[i]);
    }

    sort(children, children+numChildren);

    int left = 0;
    int right = numChildren - 1;

    int boats = 0;

    while (left <= right)
    {

        if (left == right)
        {
            boats++;
            break;
        }

        if (children[left] + children[right] > maxGondolaWeight)
        {
            boats++;

            right--;
        }
        else
        {
            boats++;

            left++;
            right--;
        }
    }

    printf("%d\n", boats);
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}