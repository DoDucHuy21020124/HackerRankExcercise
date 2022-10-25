SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    if (llist == NULL) {
        return llist;
    }
    SinglyLinkedListNode* newHead = new SinglyLinkedListNode(llist->data);
    SinglyLinkedListNode* temp = newHead;
    llist = llist->next;
    while (llist != NULL) {
        if (llist->data != temp->data) {
            SinglyLinkedListNode* newNode = new SinglyLinkedListNode(llist->data);
            temp->next = newNode;
            temp = temp->next;
        }
        llist = llist->next;
    }
    return newHead;
}