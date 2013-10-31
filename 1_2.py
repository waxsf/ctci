def reverse(s):
    r = ""
    for i in s:
        r = i+r
    return r


if __name__ == "__main__":
    s = "1234567"
    print reverse(s)
