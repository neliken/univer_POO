package com.company;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class calculator extends JFrame implements ActionListener {
    JTextField operand1;
    JTextField operand2;
    JTextField result_text;
    JButton output;
    JLabel result_label;


    calculator () {
        operand1 = new JTextField();
        operand1.setBounds(25, 50, 100, 40);
        operand1.setFont(new Font("Courier New", Font.BOLD, 15));
        add(operand1);

        operand2 = new JTextField();
        operand2.setBounds(175, 50, 100, 40);
        operand2.setFont(new Font("Courier New", Font.BOLD, 15));
        add(operand2);

        result_label = new JLabel("Result : ");
        result_label.setBounds(30, 125, 150, 40);
        result_label.setFont(new Font("Courier New", Font.BOLD, 15));
        add(result_label);

        result_text = new JTextField("");
        result_text.setBounds(125, 125, 150, 40);
        result_text.setFont(new Font("Courier New", Font.BOLD, 15));
        result_text.setEditable(false);
        add(result_text);


        output = new JButton("Output");
        output.setBounds(75, 200, 150, 40);
        output.setFont(new Font("Courier New", Font.BOLD, 15));
        add(output);

        output.addActionListener(this);
        setTitle("Calculator");
        setResizable(false);
        setLocationRelativeTo(null);
        setLayout(null);
        setSize(300, 300);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }


    public static class UnluckyException extends Exception{
        public UnluckyException() {
            // Call constructor of parent Exception
            super();
        }
    }

    public void actionPerformed(ActionEvent e) {

        double first_operand;
        double second_operand;
        double result;

        try {
            second_operand = Double.parseDouble(operand2.getText());

            if (second_operand == 13) {
                throw new UnluckyException();
            }
            result_text.setText(String.valueOf(String.format("%.6f", result)));

        } catch (NumberFormatException error) {

            JOptionPane.showMessageDialog(null, "Error: You must enter an integer");

        } catch (UnluckyException error) {
            JOptionPane.showMessageDialog(null, "Unlucky Number");
        }
    }


    public static void main(String[] args) {
        new calculator();
    }
}
