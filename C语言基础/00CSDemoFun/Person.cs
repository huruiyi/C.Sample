namespace _00CSDemoFun
{
    public class Person
    {
        public Person(string name, int age)
        {
            this.Name = name;
            this.Age = age;
        }

        public string Name;
        public int Age;

        public static Person operator +(Person p1, Person p2)
        {
            return new Person(p1.Name + p2.Name, p1.Age + p2.Age);
        }
    }
}