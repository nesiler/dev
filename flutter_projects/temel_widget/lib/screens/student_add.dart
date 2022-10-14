import 'package:flutter/material.dart';

import '../functions/showInfo.dart';
import '../models/student.dart';
import '../validation/student_validator.dart';

class StudentAdd extends StatefulWidget {
  List<Student> students;

  StudentAdd(List<Student> students) {
    this.students = students;
  }

  @override
  State<StatefulWidget> createState() {
    return _StudentAddState(students);
  }
}

class _StudentAddState extends State with StudentValidationMixin {
  ShowInfo showInfo = ShowInfo();

  List<Student> students;

  _StudentAddState(List<Student> students) {
    this.students = students;
  }

  var student = Student.withoutInfo();
  var formKey = GlobalKey<FormState>();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.greenAccent,
        title: Text('Öğrenci Ekle', style: TextStyle(color: Colors.white)),
      ),
      body: Container(
          margin: EdgeInsets.all(20.0),
          child: Form(
              key: formKey,
              child: Column(
                children: <Widget>[
                  buildFirstNameField(),
                  buildLastNameField(),
                  buildGradeField(),
                  buildSubmitButton(),
                ],
              ))),
    );
  }

  Widget buildFirstNameField() {
    return TextFormField(
      decoration: InputDecoration(labelText: 'Öğrenci Adı', hintText: 'Ahmet'),
      validator: validateFirstName,
      onSaved: (String value) {
        student.firstName = value;
      },
    );
  }

  Widget buildLastNameField() {
    return TextFormField(
      decoration: InputDecoration(labelText: 'Öğrenci Soyadı', hintText: 'Kaya'),
      validator: validateLastName,
      onSaved: (String value) {
        student.lastName = value;
      },
    );
  }

  Widget buildGradeField() {
    return TextFormField(
      decoration: InputDecoration(labelText: 'Aldığı Not', hintText: '90'),
      validator: validateGrade,
      onSaved: (String value) {
        student.grade = int.parse(value);
      },
    );
  }

  Widget buildSubmitButton() {
    return RaisedButton(
      child: Text('Kaydet'),
      onPressed: () {
        if (formKey.currentState.validate()) {
          formKey.currentState.save();
          students.add(student);
          Navigator.pop(context);
        }
      },
    );
  }

  Future<void> saveStudent() async {
    print(student.firstName);
    print(student.lastName);
    print(student.grade);
  }
}
