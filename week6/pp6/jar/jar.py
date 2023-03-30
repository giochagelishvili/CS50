class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError("Invalid Capacity")
        else:
            self.capacity = capacity
            self.size = 3

    def __str__(self):
        return self.size * '🍪'

    def deposit(self, n):
        if n > self.capacity - self.size:
            raise ValueError("Not enough capacity")
        else:
            self.size += n

    def withdraw(self, n):
        if n > self.size:
            raise ValueError("Not enough cookies")
        else:
            self.size -= n

    @property
    def capacity(self):
        return self.capacity

    @property
    def size(self):
        return self.size

jar = Jar()
jar.deposit(2)
jar.withdraw(1)
print(jar)