#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
};
struct node *middle(struct node *start, struct node *last){
    if(start == NULL)
        return NULL;
    struct node *slow = start;
    struct node *fast = start->next;

    while(fast != last){
        fast = fast->next;
        if(fast != last){
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

struct node *middle(struct node *start, struct node *last){
    if(start == NULL)
        return NULL;
    struct node *slow = start;
    struct node *fast = start->next;

    while(fast != last){
        fast = fast->next;
        if(fast != last){
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

struct node *middle(struct node *start, struct node *last){
    if(start == NULL)
        return NULL;
    struct node *slow = start;
    struct node *fast = start->next;

    while(fast != last){
        fast = fast->next;
        if(fast!=last){
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

struct node *middle(struct node *start, struct node *last){
    if(start == NULL)
        return NULL;
    struct node *slow = start;
    struct node *fast = start->next;

    while(fast != last){
        fast = fast->next;
        if(fast != last){
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

struct node *binarySearch(struct node *head, int value){
    struct node *start = head;
    struct node *last = NULL;

    do{
        struct node *mid = middle(start, last);

        if(mid->data == value)
            return mid;
        else if(mid->data < value)
            start = mid->next;
        else 
            last = mid;
    }while(last == NULL || last != start);
    
    return NULL;
}

struct node *binarySearch(struct node *head, int value){
    struct node *start = head;
    struct node *last = NULL;

    do{
        struct node *mid = middle(start, last);

        if(mid->data == value)
            return mid;
        else if(mid->data < value)
            start = mid->next;
        else    
            last = mid;
    }while((last == NULL) || (last != start));
    return NULL;
}

struct node *binarySearch(struct node *head, int value){
    struct node *start = head;
    struct node *last = NULL;

    do{
        struct node *mid = middle(start, last);
        if(mid->data == value)
            return mid;
        else if(mid->data < value)
            start = mid->next;
        else 
            last = mid;
    }while((last != NULL) || last != start);

    return NULL;
}

struct node *binarySearch(struct node *head, int value){
    struct node *start = head;
    struct node *last = NULL;

    do{
        struct node *mid = middle(start, last);

        if(mid->data == value)
            return mid;
        else if(mid->data < value)
            start = mid->next;
        else 
            last = mid;
    }while(last != NULL || last != start);
    return NULL;
}


struct node *middle(struct node *start, struct node *last){
    if(start == NULL)
        return NULL;

    struct node *slow = start;
    struct node *fast = start->next;

    while(fast != last){
        fast = fast->next;
        if(fast != last){
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

struct node *binarySearch(struct node *head, int value){
    struct node *start = head;
    struct node *last = NULL;

    do{
        struct node *mid = middle(start, last);
        if(mid->data == value)
            return mid;
        else if(mid->data < value)
            start = mid->next;
        else 
            last = mid;
    }while(last != NULL || last != start);

    return NULL;
}

struct node *middle(struct node *start, struct node *last){
    if(start == NULL)
        return NULL;
    
    struct node *slow = start;
    struct node *fast = start->next;

    while(fast != last){
        fast = fast->next;
        if(fast != last){
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

struct node *binarySearch(struct node *head, int value){
    struct node *start = head;
    struct node *last = NULL;

    do{
        struct node *mid = middle(start, last);
        if(mid->data == value)
            return mid;
        else if(mid->data < value)
            start = mid->next;
        else    
            last = mid;
    }while (last!= NULL || last != start);
    return NULL;
}


struct node *middle(struct node *start, struct node *last){
    if(start == NULL)
        printf("");
    
    struct node *slow = start;
    struct node *fast = start->next;

    while(fast != last){
        fast = fast->next;
        if(fast != last){
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

struct node *binarySearch(struct node *head, int value){
    struct node *start = head;
    struct node *last = NULL;

    do{
        struct node *mid = middle(start, last);
        if(mid->data == value)
            return mid;
        else if(mid->data < value)
            start = mid->next;
        else    
            last = mid;

    }while(last!=NULL || last!= start);
    return NULL;
}