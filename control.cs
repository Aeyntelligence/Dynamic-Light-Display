using System.IO.Ports;
using UnityEngine;
using UnityEngine.UI;

public class control : MonoBehaviour
{
    public Button redButton, greenButton, blueButton, patternButton;
    private SerialPort serialPort = new SerialPort("COM3", 9600); // Adjust COM port as necessary

    void Start()
    {
        // Open the serial port connection
        if (!serialPort.IsOpen)
        {
            serialPort.Open();
            serialPort.ReadTimeout = 1;
        }

        // Add button listeners
        redButton.onClick.AddListener(TurnRed);
        greenButton.onClick.AddListener(TurnGreen);
        blueButton.onClick.AddListener(TurnBlue);
        patternButton.onClick.AddListener(ChangePattern);
    }

    void TurnRed()
    {
        if (serialPort.IsOpen)
            serialPort.WriteLine("R");  // Command to turn light red
    }

    void TurnGreen()
    {
        if (serialPort.IsOpen)
            serialPort.WriteLine("G");  // Command to turn light green
    }

    void TurnBlue()
    {
        if (serialPort.IsOpen)
            serialPort.WriteLine("B");  // Command to turn light blue
    }

    void ChangePattern()
    {
        if (serialPort.IsOpen)
            serialPort.WriteLine("P");  // Command to change pattern
    }

    void OnApplicationQuit()
    {
        if (serialPort.IsOpen)
            serialPort.Close();
    }
}
