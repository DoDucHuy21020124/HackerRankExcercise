bool has_cycle(SinglyLinkedListNode* head) {
    vector<SinglyLinkedListNode*> checkNode;
    SinglyLinkedListNode* temp = head;
    while (temp != NULL) {
        for (int i = 0; i < checkNode.size(); ++i) {
            if (temp == checkNode[i]) {
                return true;
            }
        }
        SinglyLinkedListNode* cur = temp;
        checkNode.push_back(cur);
        temp = temp->next;
    }
    return false;
}