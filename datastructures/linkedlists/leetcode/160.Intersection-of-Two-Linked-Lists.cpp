
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return nullptr;

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
            while (diff--)
                traverseA = traverseA->next;
        else
            while (diff--)
                traverseB = traverseB->next;

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