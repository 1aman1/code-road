class Solution
{
public:
    int numSteps(string s)
    {
        const int SIZE = s.size();
        int stepsPerformed = 0;
        bool carryBit = false;

        for (int idx = SIZE - 1; idx > 0; --idx)
        {
            char thisBit = s[idx];

            if (carryBit)
            {
                if (thisBit == '1')
                {
                    thisBit = '0';
                    carryBit = true;
                }
                else
                {
                    carryBit = false;
                }
            }

            if (thisBit == '1')
            {
                ++stepsPerformed;
                carryBit = true;
            }

            ++stepsPerformed;
        }

        if (carryBit)
            ++stepsPerformed;

        return stepsPerformed;
    }
};
