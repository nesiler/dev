import 'package:flutter/material.dart';
import 'package:get/get.dart';

import '../models/student.dart';

class ShowInfo {
  void snackBarInfo(String message, Color clr) {
    Get.showSnackbar(GetBar(
        messageText: Text(
          message,
          textAlign: TextAlign.center,
          style: TextStyle(color: Colors.black54, fontSize: 20),
        ),
        borderRadius: 10,
        borderWidth: 5,
        padding: EdgeInsets.all(1.0),
        margin: EdgeInsets.all(20.0),
        duration: Duration(milliseconds: 1000),
        backgroundColor: clr));
  }

  void snackBarInfoWithTime(String message, Color clr, int millisecond) {
    Get.showSnackbar(GetBar(
        messageText: Text(
          message,
          textAlign: TextAlign.center,
          style: TextStyle(color: Colors.black54, fontSize: 20),
        ),
        borderRadius: 10,
        borderWidth: 5,
        padding: EdgeInsets.all(1.0),
        margin: EdgeInsets.all(20.0),
        duration: Duration(milliseconds: millisecond),
        backgroundColor: clr));
  }

  void mesajGoster(BuildContext context, String message) {
    var alert = AlertDialog(
      backgroundColor: Colors.blue,
      title: (Text('İşlem Sonucu:', style: TextStyle(color: Colors.black54, fontSize: 24), textAlign: TextAlign.center)),
      content: Text(message, style: TextStyle(color: Colors.black45, fontSize: 16)),
    );
    showDialog(barrierColor: Colors.white60, context: context, builder: (BuildContext context) => alert);
  }

  void ogrenciBilgi(BuildContext context, Student student) {
    var alert = AlertDialog(
      backgroundColor: Colors.amber,
      title: (Text(student.firstName + ' ' + student.lastName, style: TextStyle(color: Colors.black, fontSize: 24), textAlign: TextAlign.center)),
      content: Text('Not Ortalaması: ' + student.grade.toString(), style: TextStyle(color: Colors.black54, fontSize: 16)),
    );
    showDialog(barrierColor: Colors.white60, context: context, builder: (BuildContext context) => alert);
  }

  Icon buildStatusIcon(int grade) {
    if (grade >= 50) {
      return (Icon(Icons.done, color: Color.fromRGBO(0, 183, 181, 1), size: 24));
    } else if (grade >= 40) {
      return Icon(Icons.swap_horizontal_circle_outlined, color: Color.fromRGBO(0, 183, 181, 1), size: 24);
    } else {
      return Icon(Icons.clear, color: Color.fromRGBO(0, 183, 181, 1), size: 24);
    }
  }

  ShowInfo();
}
