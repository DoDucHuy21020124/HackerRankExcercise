int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    int data = 0;
    while (head2 != NULL) {
        SinglyLinkedListNode* temp = head1;
        while (temp != NULL) {
            if (temp == head2) {
                return temp->data;
            } else {
                temp = temp->next;
            }
        }
        head2 = head2->next;
    }
    return data;
}
