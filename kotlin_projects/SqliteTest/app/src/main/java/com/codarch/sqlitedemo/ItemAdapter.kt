package com.codarch.sqlitedemo

import android.content.Context
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import android.widget.LinearLayout
import android.widget.TextView
import androidx.core.content.ContextCompat
import androidx.recyclerview.widget.RecyclerView

class Adapter(
    private val context: Context, private val items: MutableList<EmpModelClass>
) :
    RecyclerView.Adapter<Adapter.LandmarkHolder>() {

    class LandmarkHolder(view: View) : RecyclerView.ViewHolder(view) {

        val tvName: TextView = view.findViewById(R.id.tvName)
        val tvEmail: TextView = view.findViewById(R.id.tvEmail)

        fun bindItems(item: EmpModelClass) {
            tvName.text = item.name
            tvEmail.text = item.email
        }

    }

    /**
     * Inflates the item views which is designed in the XML layout file
     *
     * create a new
     * {@link ViewHolder} and initializes some private fields to be used by RecyclerView.
     */
    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): LandmarkHolder {
        return LandmarkHolder(
            LayoutInflater.from(parent.context).inflate(R.layout.item_row, parent, false)
        )
    }

    /**
     * Binds each item in the ArrayList to a view
     *
     * Called when RecyclerView needs a new {@link ViewHolder} of the given type to represent
     * an item.
     *
     * This new ViewHolder should be constructed with a new View that can represent the items
     * of the given type. You can either create a new View manually or inflate it from an XML
     * layout file.
     */
    /*override fun onBindViewHolder(holder: ViewHolder, position: Int) {


        val item = items.get(position)
        //bindItems(items[position])

        val tvName: TextView = holder.itemView.findViewById(R.id.tvName)
        val tvEmail: TextView = holder.itemView.findViewById(R.id.tvEmail)
        val ivEdit: ImageButton = holder.itemView.findViewById(R.id.ivEdit)
        val ivDelete: ImageButton = holder.itemView.findViewById(R.id.ivDelete)
        val llMain: LinearLayout = holder.itemView.findViewById(R.id.llMain)


         tvName.text = item.name
         tvEmail.text = item.email

        // Updating the background color according to the odd/even positions in list.
        if (position % 2 == 0) {
            holder.llMain.setBackgroundColor(
                ContextCompat.getColor(
                    context,
                    R.color.colorLightGray
                )
            )
        } else {
            holder.llMain.setBackgroundColor(ContextCompat.getColor(context, R.color.colorWhite))
        }

         ivEdit.setOnClickListener { view ->
             println("ivedit button+++++++++++++++")

             if (context is MainActivity) {
                 context.updateRecordDialog(item)
             }
         }

         ivDelete.setOnClickListener { view ->
             println("ivdelete button----------------------")


             if (context is MainActivity) {
                 context.deleteRecordAlertDialog(item)
             }
         }
    }*/

    /**
     * Gets the number of items in the list
     */
    override fun getItemCount(): Int {
        return items.size
    }

    /**
     * A ViewHolder describes an item view and metadata about its place within the RecyclerView.
     */
    class ViewHolder(view: View) : RecyclerView.ViewHolder(view) {

        val tvName: TextView = view.findViewById(R.id.tvName)
        val tvEmail: TextView = view.findViewById(R.id.tvEmail)
        val ivEdit: Button = view.findViewById(R.id.ivEdit)
        val ivDelete: Button = view.findViewById(R.id.ivDelete)
        val llMain: LinearLayout = view.findViewById(R.id.llMain)

    }

    override fun onBindViewHolder(holder: LandmarkHolder, position: Int) {

        holder.bindItems(items[position])

        /*val tvName: TextView = holder.itemView.findViewById(R.id.tvName)
        val tvEmail: TextView = holder.itemView.findViewById(R.id.tvEmail)*/

        val ivEdit: Button = holder.itemView.findViewById(R.id.ivEdit)
        val ivDelete: Button = holder.itemView.findViewById(R.id.ivDelete)
        val llMain: LinearLayout = holder.itemView.findViewById(R.id.llMain)

        // Updating the background color according to the odd/even positions in list.
        if (position % 2 == 0) {
            llMain.setBackgroundColor(
                ContextCompat.getColor(
                    context,
                    R.color.colorLightGray
                )
            )
        } else {
            llMain.setBackgroundColor(ContextCompat.getColor(context, R.color.colorWhite))
        }

        ivEdit.setOnClickListener {
             if (context is MainActivity) {
                 context.updateRecordDialog(items[position])
             }
         }

         ivDelete.setOnClickListener {
             if (context is MainActivity) {
                 context.deleteRecordAlertDialog(items[position])
             }
         }
    }
}