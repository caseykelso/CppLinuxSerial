#include <CppLinuxSerial/SerialPort.hpp>

using namespace mn::CppLinuxSerial;

// Overload to be able to print vectors to std::cout
template <typename T>
std::ostream& operator<<( std::ostream& ostrm, const std::vector<T>& vec ){
    for( int j = 0, n = vec.size(); j < n; ++j ){
        ostrm << ",["[ !j ] << " " << vec[ j ];
    }
    return ostrm << " ]";
}

int main() {
	// Create serial port object and open serial port
    SerialPort serialPort("/dev/ttyACM0", BaudRate::B_9600, NumDataBits::EIGHT, Parity::NONE, NumStopBits::ONE);
	// SerialPort serialPort("/dev/ttyACM0", 13000);
    serialPort.SetTimeout(-1); // Block when reading until any data is received
	serialPort.Open();

	// Write some ASCII datae
	// serialPort0.Write("Hello");

	// Read some data back
    // while(1) {
    //     std::string readData;
    //     serialPort.Read(readData);
    //     std::cout << "Received data: " << readData;
    // }

	// Read some data back (raw)
    while(1) {
        std::vector<unsigned char> readData;
        serialPort.ReadBinary(readData);
        std::cout << "Received data: " << readData;
    }

	// Close the serial port
	serialPort.Close();
}