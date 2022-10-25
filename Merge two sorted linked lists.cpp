SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* newHead = new SinglyLinkedListNode(0);
    SinglyLinkedListNode* temp = newHead;
    while (head1 != NULL || head2 != NULL) {
        if (head1 == NULL) {
            SinglyLinkedListNode* newNode = new SinglyLinkedListNode(head2->data);
            temp->next = newNode;
            temp = temp->next;
            head2 = head2->next;
        } else if (head2 == NULL) {
            SinglyLinkedListNode* newNode = new SinglyLinkedListNode(head1->data);
            temp->next = newNode;
            temp = temp->next;
            head1 = head1->next;
        } else {
            if (head1->data < head2->data) {
                SinglyLinkedListNode* newNode = new SinglyLinkedListNode(head1->data);
                temp->next = newNode;
                temp = temp->next;
                head1 = head1->next;
            } else {
                SinglyLinkedListNode* newNode = new SinglyLinkedListNode(head2->data);
                temp->next = newNode;
                temp = temp->next;
                head2 = head2->next;
            }
        }
    }
    return newHead->next;

}