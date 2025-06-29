int Solution::removeElement(vector<int> &A, int B)
{
    int left = 0, size = A.size();

    for (int i = 0; i < size; i++)
    {
        if (A[i] != B)
        {
            A[left++] = A[i];
        }
    }
    return left;
}
