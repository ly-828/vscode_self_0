#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#define N 20000
struct Student
{
    int score;
    struct Student *next;
};
//创建单向键表,返回链表表头head
struct Student *CreatLink(struct Student *head, int n)
{
    int i;
    struct Student *p1, *p2;
    head = p1 = (struct Student *)malloc(sizeof(struct Student));
    if (p1 == NULL)
    {
        printf("Not enough memory to allocate buffer\n");
        system("PAUSE");
        exit(1); /* terminate program if out of memory */
    }
    p1->score = rand() % 101; //产生随机值
    p1->next = NULL;
    for (i = 2; i <= n; i++)
    {
        p2 = p1;
        p1 = (struct Student *)malloc(sizeof(struct Student));
        if (p1 == NULL)
        {
            printf("Not enough memory to allocate buffer\n");
            system("PAUSE");
            exit(1); /* terminate program if out of memory */
        }
        p1->score = rand() % 101; //产生随机值
        p1->next = NULL;
        for (i = 2; i <= n; i++)
        {
            p2 = p1;
            p1 = (struct Student *)malloc(sizeof(struct Student));
            if (p1 == NULL)
            {
                printf("Not enough memory to allocate buffer\n");
                system("PAUSE");
                exit(1); /* terminate program if out of memory */
            }
            p1->score = rand() % 101;
            p1->next = NULL; //最近产生的节点下一节点指向空
            p2->next = p1;
        }
        return head;
    }
}
    //显示循环链表的成员
    void DisplayLink(struct Student * head)
    {
        struct Student *p;
        p = head;
        do
        {
            printf("%3d ", p->score);
            p = p->next;
        } while (p != NULL); //p再次与head相等时，即所有成员都遍历完成
        printf("\n\n");
    }
    //选择排序法排序链表
    struct Student *SortLink(struct Student * head)
    {
        struct Student *head2 = NULL, *p1, *p2, *p1lst, *p2lst, *q;
        float MaxScore;
        while (head != NULL)
        {
            p2 = p1 = head;
            MaxScore = head->score;
            while (p1 != NULL)
            {
                if (p1->score > MaxScore)
                {
                    MaxScore = p1->score;
                    p2lst = p1lst;
                    p2 = p1;
                }
                p1lst = p1;
                p1 = p1->next;
            }
            if (p2 == head)
            {
                head = head->next;
            }
            else
            {
                p2lst->next = p2->next;
            }
            if (head2 == NULL)
            {
                head2 = q = p2;
            }
            else
            {
                q->next = p2;
                q = q->next;
            }
        }
        q->next = NULL;
        return head2;
    }
    int main(int argc, char *argv[])
    {
        struct Student *head;
        srand((unsigned)time(NULL));
        head = CreatLink(head, N);
        printf("The sorces random Generated :\n");
        DisplayLink(head);
        head = SortLink(head);
        printf("After Sort The sorces are follows:\n");
        DisplayLink(head);
        free(head);
        system("PAUSE");
        return 0;
    }