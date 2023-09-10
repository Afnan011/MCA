public class AbstractDemo {
    public static void main(String[] args) {
        
        Animal c1;

        c1 = new PersianCat("afnan", 21);
        c1.eat();
        c1.getName();
        c1.getAge();

    }
}

abstract class Animal
{
    abstract void getName();
    abstract void getAge();

    void eat()
    {
        System.out.println("Animal is eating");
    }
}

abstract class Cat extends Animal
{   
    String name;

    Cat(String name)
    {
        this.name = name;
    }

    void getName()
    {
        System.out.println("Name = " + name);
    }
}

class PersianCat extends Cat
{
    String name;
    int age;

    PersianCat(String name, int age)
    {
        super(name);
        this.age = age;
    }

    void getAge()
    {
        System.out.println("Age = " + age);
    }
}
