import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter/widgets.dart';
import 'package:get/get.dart';

import 'functions/showInfo.dart';
import 'models/student.dart';
import 'screens/student_add.dart';
import 'screens/student_edit.dart';

void main() {
  runApp(
    GetMaterialApp(home: MyApp(), debugShowCheckedModeBanner: false),
  );
}

class MyApp extends StatefulWidget {
  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  ShowInfo showInfo = ShowInfo();
  Student selectedStudent = Student.withId(0, '', '', 0);

  List<Student> students = [
    Student.withId(1, 'Enes', 'Diler', 25),
    Student.withId(2, 'Mbappe', 'Degirmenci', 20),
    Student.withId(3, 'Hilmi', 'Aratekin', 75),
    Student.withId(4, 'Aliyan', 'Durmuş', 55),
    Student.withId(5, 'Ahmet', 'Ermiş', 95),
    Student.withId(6, 'Mustafa', 'Kocayılmaz', 65),
    Student.withId(7, 'Kemal', 'Ayvaz', 35),
    Student.withId(8, 'İlyas', 'Karaağaçlı', 85),
    Student.withId(9, 'Metehan', 'Bağcı', 45),
    Student.withId(10, 'Ferhat', 'Kocakaya', 100),
    Student.withId(11, 'Muhammed', 'Akargül', 5),
    Student.withId(12, 'İsmail', 'Kayış', 41),
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        backgroundColor: Colors.lightBlue,
        appBar: AppBar(
            backgroundColor: Colors.lightBlue,
            title: Center(
                child: Text('OBS',
                    style: TextStyle(color: Colors.amber, fontSize: 48),
                    textAlign: TextAlign.center))),
        body: buildBody(context));
  }

  // ignore: missing_return
  Widget buildBody(BuildContext context) {
    return Column(
      mainAxisAlignment: MainAxisAlignment.center,
      crossAxisAlignment: CrossAxisAlignment.center,
      children: <Widget>[
        Expanded(
          child: ListView.builder(
              itemCount: students.length,
              itemBuilder: (BuildContext context, int index) {
                return Column(
                  children: [
                    Card(
                      color: Colors.amber,
                      elevation: 3.0,
                      child: ListTile(
                        leading: CircleAvatar(
                          backgroundImage: NetworkImage(
                              'https://img.geocaching.com/track/display/ced5f668-16fa-4b99-bf3c-3f8014dcda88.jpg'),
                        ),
                        title: Text(
                            '' +
                                students[index].firstName +
                                ' ' +
                                students[index].lastName,
                            style: TextStyle(
                              color: Colors.black54,
                              fontSize: 24,
                            ),
                            textAlign: TextAlign.start),
                        subtitle: Text(
                            'Öğrencinin Sınavdan Aldığı Not: ' +
                                students[index].grade.toString() +
                                ' [' +
                                students[index].getStatus +
                                ']',
                            style:
                                TextStyle(fontSize: 12, color: Colors.black45)),
                        trailing:
                            showInfo.buildStatusIcon(students[index].grade),
                        onLongPress: () {
                          setState(() {
                            showInfo.ogrenciBilgi(context, students[index]);
                          });
                        },
                        onTap: () {
                          setState(() {
                            selectedStudent = students[index];
                            showInfo.snackBarInfoWithTime(
                                ('Secili Ogrenci: ' +
                                    selectedStudent.firstName +
                                    ' ' +
                                    selectedStudent.lastName),
                                Colors.white54,
                                750);
                          });
                        },
                      ),
                    ),
                  ],
                );
              }),
        ),
        Row(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Flexible(
                fit: FlexFit.tight,
                flex: 1,
                // ignore: deprecated_member_use
                child: RaisedButton(
                  color: Colors.greenAccent,
                  child: Row(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: <Widget>[
                      Icon(Icons.add),
                      SizedBox(
                        width: 3,
                      ),
                      Text('Ekle',
                          style: TextStyle(color: Colors.black, fontSize: 20),
                          textAlign: TextAlign.center),
                    ],
                  ),
                  onPressed: () {
                    Navigator.push(
                        context,
                        MaterialPageRoute(
                            builder: (context) => StudentAdd(students)));
                  },
                )),
            Flexible(
                fit: FlexFit.tight,
                flex: 1,
                // ignore: deprecated_member_use
                child: RaisedButton(
                  color: Colors.amber,
                  child: Row(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                      Icon(Icons.refresh),
                      SizedBox(
                        width: 2,
                      ),
                      Text('Güncelle',
                          style: TextStyle(color: Colors.black, fontSize: 20),
                          textAlign: TextAlign.center),
                    ],
                  ),
                  onPressed: () {
                    Navigator.push(
                        context,
                        MaterialPageRoute(
                            builder: (context) =>
                                StudentEdit(selectedStudent)));
                  },
                )),
            Flexible(
                fit: FlexFit.tight,
                flex: 1,
                // ignore: deprecated_member_use
                child: RaisedButton(
                  color: Colors.redAccent,
                  child: Row(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                      Icon(Icons.delete),
                      SizedBox(
                        width: 3,
                      ),
                      Text(
                        'Sil',
                        style: TextStyle(color: Colors.black, fontSize: 20),
                        textAlign: TextAlign.start,
                      ),
                    ],
                  ),
                  onPressed: () {
                    setState(() {
                      students.remove(selectedStudent);
                    });
                    var message = 'Silindi: ' +
                        selectedStudent.firstName +
                        ' ' +
                        selectedStudent.lastName;
                    showInfo.snackBarInfo(message, Colors.redAccent);
                  },
                  focusColor: Colors.greenAccent,
                )),
          ],
        ),
        //Text('Seçili Öğrenci: ' + selectedStudent.firstName, style: TextStyle(color: Colors.black45, fontSize: 12), textAlign: TextAlign.center),
      ],
    );
  }
}
