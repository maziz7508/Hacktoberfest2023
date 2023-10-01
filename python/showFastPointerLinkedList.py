# Default Impl
class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

# Slow fast default
slow, fast = head, head
while fast and fast.next:
	slow = slow.next
	fast = fast.next.next