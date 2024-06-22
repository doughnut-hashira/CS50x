
operaters : list[str] = ['+','-','*','**','/','%']

def valid(operater : str) -> bool:
    return operater in operaters

def calculater(operater: str, no1: int, no2: int) -> int:
    code = f"{str(no1)} {operater} {str(no2)}"
    ans = eval(code)
    return ans

def main():
    no1: int = int(input('number1 = '))
    no2: int = int(input('number2 = '))
    operater: str = input("operater = ")
    if (valid(operater) == False):
        print(f"invalid operater {operater}")
        return
    ans = calculater(operater, no1, no2)
    print(ans)


if __name__ == "__main__":
    main()


#def hello() -> bool:
#    name : str = input("what is your name? ")
#    print(f"hello {name}")
#    return bool(name)

#if __name__ == "__main__":
#    if(hello() == False):
#        print("name not found")
