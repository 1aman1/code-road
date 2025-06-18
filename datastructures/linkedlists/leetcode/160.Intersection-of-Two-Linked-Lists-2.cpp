class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        // 1.
        ListNode *traverseA = nullptr, *traverseB = nullptr;
        int lengthA, lengthB, diff;

        traverseA = headA;
        traverseB = headB;
        lengthA = lengthB = 0;

        while (traverseA)
        {
            ++lengthA;
            traverseA = traverseA->next;
        }
        while (traverseB)
        {
            ++lengthB;
            traverseB = traverseB->next;
        }

        diff = abs(lengthA - lengthB);

        traverseA = headA;
        traverseB = headB;

        if (lengthA > lengthB)
        {
            while (diff)
            {
                traverseA = traverseA->next;
                --diff;
            }
        }
        else
        {
            while (diff)
            {
                traverseB = traverseB->next;
                --diff;
            }
        }

        while (traverseA && traverseB)
        {
            if (traverseA == traverseB)
            {
                return traverseA;
            }
            traverseA = traverseA->next;
            traverseB = traverseB->next;
        }
        return nullptr;
    }
};