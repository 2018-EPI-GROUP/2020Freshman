struct LinkList {  
    int value;  
    LinkList *next;  
};  
/*根据输入建立单链表
将输入的节点插入到链表头部。*/

LinkList *BuildList() {  
    LinkList *head = NULL;  
    int data;  
    int i = 0;  
    while (scanf("%d", &data) != EOF) {  
        //scanf("%d", &data);++i;  
        LinkList *new_node = (LinkList *)malloc(sizeof(LinkList));  
        if (NULL == new_node) {  
            fprintf(stderr, "malloc failed");  
            return head;  
        }  
        new_node->value = data;  
        if (head == NULL) {  
            new_node->next = NULL;  
            head = new_node;  
        }  
        else {  
            new_node->next = head;  
            head = new_node;  
        }  
    }  
    return head;  
}  
//在链表头部插入节点  
LinkList *InsertToHead(int value, LinkList *head) {  
    LinkList *new_node = (LinkList *)malloc(sizeof(LinkList));  
    if (new_node == NULL) {  
        fprintf(stderr, "malloc failed");  
        return head;  
    }  
    new_node->value = value;  
    new_node->next = NULL;  
    if (head == NULL) {  
        head = new_node;  
    }  
    else {  
        new_node->next = head;  
        head = new_node;  
    }  
    return head;  
}  
//链表尾部插入节点
LinkList *InsertToTail(int value, LinkList *head) {
    LinkList *new_node = (LinkList *)malloc(sizeof(LinkList));
    if (new_node == NULL) {
        fprintf(stderr, "malloc failed");
        return head;
    }
    new_node->value = value;
    new_node->next = NULL;

    if (head == NULL)
        head = new_node;
    else {
        LinkList *pnode = head;
        while (pnode->next != NULL)
            pnode = pnode->next;
        pnode->next = new_node;
    }
    return head;
}
//删除某节点  
LinkList *DeletebyValue(int value, LinkList* head) {  
    if (head == NULL)  
        return head;  
    LinkList *pToDelete = NULL;  
    if (head->value == value) {  
        pToDelete = head;  
        head = head->next;  
    }  
    else {  
        LinkList *p = head;  
        while (p->next != NULL && p->next->value != value)  
            p = p->next;  
        if (p->next != NULL) {  
            pToDelete = p->next;  
            p->next = pToDelete->next;  
        }  
    }  
    if (pToDelete != NULL) {  
        free(pToDelete);  
        pToDelete = NULL;  
    }  
    return head;  
}  
//求单链表中结点的个数
//注意检查链表是否为空。时间复杂度为O（n）。该操作不用特意检查链表是否为空，如下代码，链表为空会返回0。

unsigned int Length(LinkList *head) {  
    unsigned int length = 0;  
    LinkList *p = head;  
    while (p) {  
        ++length;  
        p = p->next;  
    }  
    return length;  
}  
//打印单链表  顺序 
void PrintList(LinkList *head) {  
    LinkList *p = head;  
    while (p) {  
        printf("%d ", p->value);  
        p = p->next;  
    }  
    printf("\n");  
}  
//逆序打印单链表：非递归  
void RPrintList(LinkList* head) {  
    if (NULL == head)  
        return;  
    stack<int> list_stack;  
    while (head) {  
        list_stack.push(head->value);  
        head = head->next;  
    }  
    while (!list_stack.empty()) {  
        printf("%d ", list_stack.top());  
        list_stack.pop();  
    }  
    printf("\n");  
}  
  
//逆序打印单链表：递归  
void RPrintListRecursively(LinkList* head) {  
    if (NULL == head)  
        return;  
    else {  
        RPrintListRecursively(head->next);  
        printf("%d ", head->value);  
    }  
}  
