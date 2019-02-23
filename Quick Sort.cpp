struct ListNode *getTail(struct ListNode *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

// Partitions the list taking the last element as the pivot
struct ListNode *partition(struct ListNode *head, struct ListNode *end,
                       struct ListNode **newHead, struct ListNode **newEnd)
{
    struct ListNode *pivot = end;
    struct ListNode *prev = NULL, *cur = head, *tail = pivot;

    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            // First ListNode that has a value less than the pivot - becomes
            // the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        }
        else // If cur ListNode is greater than pivot
        {
            // Move cur ListNode to next of tail, and change tail
            if (prev)
                prev->next = cur->next;
            struct ListNode *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    // If the pivot data is the smallest element in the current list,
    // pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;

    // Update newEnd to the current last ListNode
    (*newEnd) = tail;

    // Return the pivot ListNode
    return pivot;
}


//here the sorting happens exclusive of the end ListNode
struct ListNode *quickSortRecur(struct ListNode *head, struct ListNode *end)
{
    // base condition
    if (!head || head == end)
        return head;

    ListNode *newHead = NULL, *newEnd = NULL;

    // Partition the list, newHead and newEnd will be updated
    // by the partition function
    struct ListNode *pivot = partition(head, end, &newHead, &newEnd);

    // If pivot is the smallest element - no need to recur for
    // the left part.
    if (newHead != pivot)
    {
        // Set the ListNode before the pivot ListNode as NULL
        struct ListNode *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);

        // Change next of last ListNode of the left half to pivot
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }

    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

// The main function for quick sort. This is a wrapper over recursive
// function quickSortRecur()
ListNode* Solution::sortList(ListNode* A) {

      A = quickSortRecur(A, getTail(*headRef));
    return;
}
