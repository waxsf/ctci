def isUnique(s):
    check = 0
    for i in s:
        pos = ord(i)
        if check&(1<<pos):
            return False
        else:
            check |= 1<<pos
    return True


if __name__ == "__main__":
    s = "abca"
    print isUnique(s)
