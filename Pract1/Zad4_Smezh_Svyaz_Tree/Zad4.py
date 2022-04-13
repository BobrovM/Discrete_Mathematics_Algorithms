#Задание 4.
#Написать программы для смежного и связного представлений абстрактных объектов (деревьев)

#Смежное представление абстрактных объектов
from typing import List


def insertSmezh(inputSmezhTree):
    if isinstance(inputSmezhTree, List):
        #todo print vvod
        print("Введите значение:")
        #todo vvod
        1
    else:
        2

#Связанное представление абстрактных деревьев
class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data
    def insert(self, data):
        if self.data:
            if data < self.data:
                if self.left is None:
                    self.left = Node(data)
                else:
                    self.left.insert(data)
            elif data > self.data:
                if self.right is None:
                    self.right = Node(data)
                else:
                    self.right.insert(data)
            else:
                self.data = data
    def delete(self, key):
        # если значение элемента равно заданному
        if self.data == key: 
            if self.right and self.left:
                [cur_root, r_min] = self.right.getMin(self) #в правом поддереве находим меньший элемент и его предка
                if cur_root.left == r_min:
                    cur_root.left = r_min.right
                else:
                    cur_root.right = r_min.right
                r_min.left = self.left # присваеваем минимуму поддеревья удаленного элемента
                r_min.right = self.right
                return r_min
            else:
                if self.left:
                    return self.left
                else:
                    return self.right
        else:
            # искомый элемент в левом поддереве
            if self.data > key: 
                if self.left:
                    self.left = self.left.delete(key)
            # искомый элемент в правом поддереве    
            else: 
                if self.right:
                    self.right = self.right.delete(key)
        return self
    # возвращает самый меньший элемент теущего поддерева и его корень
    def getMin(self, parent):
        if self.left:
            return self.left.getMin(self)
        else:
            return [parent, self]
    def printOut(self, root):
        res = []
        if root:
            res.append(root.data)
            res = res + self.printOut(root.left)
            res = res + self.printOut(root.right)
        return res

#todo while, с выбором действий
root = Node(27)
root.insert(14)
root.insert(35)
root.insert(10)
root.insert(19)
root.insert(31)
root.insert(42)
root.insert(8)
root.insert(12)
root.insert(2)
root.insert(1)
root.insert(30)
root.insert(29)
root.insert(17)
root.insert(20)
root.delete(14)
print(root.printOut(root))