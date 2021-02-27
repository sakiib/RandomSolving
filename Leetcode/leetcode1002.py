def commonChars(self, a):
        return list(reduce(collections.Counter.__and__, map(collections.Counter, a)).elements())
