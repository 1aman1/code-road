void remove_kth_from_back(int pos)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (pos >= 0)
    {
        --pos;
        fast = fast->next;
    }

    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode *tmp = slow->next;
    slow->next = slow->next->next;
    delete tmp;
}
