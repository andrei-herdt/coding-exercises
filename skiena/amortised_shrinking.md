### 3-5. 
We have seen how dynamic arrays enable arrays to grow while still achiev-
ing constant-time amortized performance. This problem concerns extending
dynamic arrays to let them both grow and shrink on demand.
(a) Consider an underﬂow strategy that cuts the array size in half whenever
the array falls below half full. Give an example sequence of insertions and
deletions where this strategy gives a bad amortized cost.
(b) Then, give a better underﬂow strategy than that suggested above, one that
achieves constant amortized cost per deletion.

### My solution
Sequences that would give bad amortised cost would involve insertions after shrinking.
My suggestion is to remove only half of the freed memory.

### Bard's solution
(a)

An underflow strategy that cuts the array size in half whenever the array falls below half full has a bad amortized cost if the array is repeatedly inserted to and then deleted from. For example, consider the following sequence of operations:

Insert 1, 2, 3, 4, 5
Delete 1, 2, 3, 4
Insert 6, 7, 8, 9, 10
Delete 5, 6, 7, 8, 9, 10
After this sequence of operations, the array will be empty. However, the array will have been resized 4 times, even though it was only ever half full once. This means that the amortized cost of each deletion is O(n), where n is the number of elements that have been inserted since the last resize.

(b)

A better underflow strategy than the one suggested above is to resize the array only when it falls below a certain threshold, such as 1/4 of its full size. This ensures that the array is not resized too often, and it also prevents the resize-delete see-saw effect that can occur with the first strategy.

For example, consider the same sequence of operations as in the previous example, but with the underflow strategy that resizes the array when it falls below 1/4 of its full size.

Insert 1, 2, 3, 4, 5
Delete 1, 2, 3, 4
Insert 6, 7, 8, 9, 10
Delete 5, 6, 7, 8, 9, 10
After this sequence of operations, the array will be empty. However, the array will only have been resized 2 times, even though it was only ever half full once. This means that the amortized cost of each deletion is O(1).

In general, any underflow strategy that resizes the array only when it falls below a certain threshold will have a constant amortized cost per deletion.

