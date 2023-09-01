def magic(self, cur=None, first_call=True) -> int:

    if first_call:
        return self.magic(self.root, False)

    if cur is None:
        return 0

    if cur.left is None and cur.right is None:
        return 1

    return self.magic(cur.left, False) + self.magic(cur.right, False)
