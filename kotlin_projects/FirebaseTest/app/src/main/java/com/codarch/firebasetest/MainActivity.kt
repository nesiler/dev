package com.codarch.firebasetest

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import com.google.firebase.database.DataSnapshot
import com.google.firebase.database.DatabaseError
import com.google.firebase.database.FirebaseDatabase
import com.google.firebase.database.ValueEventListener
import java.lang.StringBuilder


class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val database = FirebaseDatabase.getInstance().reference

        val button: Button = findViewById(R.id.button)
        val list: TextView = findViewById(R.id.list)

        button.setOnClickListener()
        {
            val number = findViewById<EditText>(R.id.personNumber).text.toString().toInt()
            val name = findViewById<EditText>(R.id.personName).text.toString()
            database.child("students").child(number.toString()).setValue(Student(number, name))
        }

        val getData = object : ValueEventListener {
            override fun onDataChange(snapshot: DataSnapshot) {
                val sb = StringBuilder()
                for (i in snapshot.children) {
                    val name = i.child("personelName").value
                    val number = i.child("personelNumber").value
                    sb.append("${i.key} $name $number \n")
                }
                list.text = sb
            }

            override fun onCancelled(error: DatabaseError) {
                TODO()
            }
        }
        database.addValueEventListener(getData)
        database.addListenerForSingleValueEvent(getData)
    }


}