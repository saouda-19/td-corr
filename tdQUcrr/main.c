
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

//EXO 03. BEGIN
// Function to reverse the queue using two stacks
void reverseQueue(Queue *q) {
    Stack stack1;
    initStack(&stack1);  // Initialize stack1

    // Step 1: Dequeue elements from the queue and push them to stack1
    while (!is_empty(q)) {
        int value = dequeue(q);
        push(&stack1, value);
    }

    // Step 2: Pop elements from stack1 and enqueue them back to the queue
    while (!is_empty_s(&stack1)) {
        int value = pop(&stack1);
        enqueue(q, value);
    }
}

//EXO 04. BEGIN
// Function to enqueue an element into the simulated queue
void enqueueUsingTwoStacks(Queue *q, Stack *stack1, Stack *stack2, int value) {
    push(stack1, value);
}

// Function to dequeue an element from the simulated queue
int dequeueUsingTwoStacks(Queue *q, Stack *stack1, Stack *stack2) {
    if (is_empty_s(stack2)) {
        // Transfer all elements from stack1 to stack2
        while (!is_empty_s(stack1)) {
            int value = pop(stack1);
            push(stack2, value);
        }
    }

    // If stack2 is still empty, the queue is empty
    if (is_empty_s(stack2)) {
        printf("Queue is empty.\n");
        return -1;
    }

    // Pop from stack2 to simulate dequeue
    return pop(stack2);
}
//EXO 04. END

//EXO 05. BEGIN


int main()
{
    //EXO 03. BEGIN
    printf("\n Exercice 03. Reversing the queue using two stacks.\n");

    Queue q;
    initializeQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);

    printf("Queue before reversal:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d ", q.queue[i]);
    }
    printf("\n");

    reverseQueue(&q);

    printf("Queue after reversal:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d ", q.queue[i]);
    }
    printf("\n");
    //EXO 03. END

    //EXO 04. BEGIN
    printf("\n Exercice 04. Simulating a queue using two stacks (one for enqueue, one for dequeue).\n");

    Stack stack1, stack2;
    initStack(&stack1);
    initStack(&stack2);

    // Enqueue operations
    enqueueUsingTwoStacks(NULL, &stack1, &stack2, 10);
    enqueueUsingTwoStacks(NULL, &stack1, &stack2, 20);
    enqueueUsingTwoStacks(NULL, &stack1, &stack2, 30);

    // Dequeue operations
    printf("Dequeued: %d\n", dequeueUsingTwoStacks(NULL, &stack1, &stack2));
    printf("Dequeued: %d\n", dequeueUsingTwoStacks(NULL, &stack1, &stack2));


/*الشرح بالعربية للكود:

الكود الذي أمامنا عبارة عن برنامج بلغة C يتعامل مع الطابور (Queue) باستخدام الأكوام (Stacks). يتضمن الكود عدة تمارين:

1. التمرين الثالث (EXO 03)
- عكس الطابور باستخدام أكوام:

في هذا الجزء، لدينا دالة reverseQueue التي تقوم بعكس محتويات الطابور باستخدام كائين من الأكوام.

الخطوات:

1. إفراغ الطابور إلى كومة (stack1):
في البداية، نقوم بسحب العناصر من الطابور باستخدام الدالة dequeue ثم نضغطها (push) في الكومة stack1.


2. إعادة إرجاع العناصر إلى الطابور من الكومة (stack1):
 بعد ذلك، نقوم بإخراج العناصر من الكومة stack1 باستخدام الدالة pop ثم نضيفها مرة أخرى إلى الطابور باستخدام الدالة enqueue.




الهدف من هذا هو عكس ترتيب العناصر في الطابور باستخدام الأكوام.

2. التمرين الرابع (EXO 04) - محاكاة الطابور باستخدام كومتين:

في هذا الجزء، يتم محاكاة طابور باستخدام كومتين (stack1 و stack2)، حيث يتم استخدام الكومة الأولى لإضافة العناصر (enqueue) والكومة الثانية لإزالة العناصر (dequeue).

إضافة عنصر إلى الطابور:

في دالة enqueueUsingTwoStacks، نقوم فقط بدفع العنصر إلى stack1.


إزالة عنصر من الطابور:

في دالة dequeueUsingTwoStacks، إذا كانت الكومة الثانية (stack2) فارغة، نقوم بنقل جميع العناصر من stack1 إلى stack2.

بعد ذلك، نقوم بإخراج العنصر من stack2 لمحاكاة عملية السحب من الطابور.

إذا كانت الكومة الثانية فارغة وكان الكومتان فارغتين، فهذا يعني أن الطابور فارغ.



3. التمرين الخامس (EXO 05):

في هذا الجزء، لا يوجد كود مُنفذ بعد، إذ لم يتم وضع أي عمليات أو دوال لهذا التمرين في الوقت الحالي.

4. البرنامج الرئيسي (main):

في الدالة main، يتم أولاً اختبار التمرين الثالث عن طريق عكس الطابور باستخدام الدالة reverseQueue ثم طباعة الطابور قبل وبعد عكسه.

بعد ذلك، يتم اختبار التمرين الرابع عن طريق محاكاة الطابور باستخدام الأكوام، مع إضافة بعض العناصر إلى الطابور، ثم إخراجها باستخدام الدوال enqueueUsingTwoStacks و dequeueUsingTwoStacks.


ملاحظات:

التراكيب المستخدمة:

Queue: هي هيكل البيانات الذي يمثل الطابور.

Stack: هي هيكل البيانات الذي يمثل الكومة.


الدوال المساعدة:

initStack: لتهيئة الكومة.

is_empty: للتحقق مما إذا كان الطابور أو الكومة فارغًا.

enqueue, dequeue: لإضافة وحذف العناصر من الطابور.

push, pop: لإضافة وحذف العناصر من الكومة.



الهدف من هذا الكود هو معالجة طابور باستخدام الأكوام بشكل فعال، ومحاكاة الطابور باستخدام الأكوام لتحقيق مفاهيم مثل الإضافة والإزالة في الطابور.
error:4*/


    return 0;
}
