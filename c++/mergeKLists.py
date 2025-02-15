# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import heapq

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        minHeap = []

        for l in lists:
            if l:
                heapq.heappush(minHeap, (l.val,id(l),l))

        dummy = ListNode(0)
        current = dummy

        while minHeap:
            val,_,l = heapq.heappop(minHeap)
            current.next = l
            current = current.next
            if l.next:
                heapq.heappush(minHeap, (l.next.val,id(l.next),l.next))
        return dummy.next


        