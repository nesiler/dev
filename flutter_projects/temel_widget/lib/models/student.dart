class Student {
  int id;
  String firstName;
  String lastName;
  int grade;

  Student(String firstName, String lastName, int grade) {
    this.firstName = firstName;
    this.lastName = lastName;
    this.grade = grade;
  }

  Student.withId(int id, String firstName, String lastName, int grade) {
    this.id = id;
    this.firstName = firstName;
    this.lastName = lastName;
    this.grade = grade;
  }

  Student.withoutInfo();

  String get getStatus {
    var message = '';
    if (grade >= 50) {
      message = ('GEÇTİ');
    } else if (grade >= 40) {
      message = ('BÜTE KALDI');
    } else {
      message = ('KALDI');
    }

    return message;
  }
}
