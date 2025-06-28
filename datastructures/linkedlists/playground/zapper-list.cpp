
void zapper(Lists list1, Lists list2)
{
    Node *zipper = list1.head;

    Node *current1 = list1.head->next;
    Node *current2 = list2.head;

    int pos = 0;

    while (current1 != nullptr && current2 != nullptr)
    {
        if (pos & 1)
        {
            zipper->next = current1;
            current1 = current1->next;
        }
        else
        {
            zipper->next = current2;
            current2 = current2->next;
        }

        zipper = zipper->next;
        ++pos;
    }

    if (current2 == nullptr)
        zipper->next = current1;
    if (current1 == nullptr)
        zipper->next = current2;
}
