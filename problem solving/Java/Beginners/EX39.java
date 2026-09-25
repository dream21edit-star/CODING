class Student {
    String name;
        int rollNumber;
        void displayInfo() {
            System.out.println("Student Name:       "+name);
            System.out.println("Student Roll Number: "+rollNumber);
        }
}
public class EX39 {
    public static void main(String[] args) {
        Student s = new Student();
        s.name = "Alice";
        s.rollNumber = 101;
        s.displayInfo();
    }
}
