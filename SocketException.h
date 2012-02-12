#include <string>

// Custom simple exception class, we need this because to compile successfully
// under windows we need to EXCLUDE the msvcrt library, which contains the
// standard exception class - so we'll just quickly knock together our own!
class SocketException
{
	private:
		std::string msg;

	public:
		SocketException(const std::string theErrorMsg)
		{
			msg = theErrorMsg;
		}

		std::string what()
		{
			return msg;
		}
};
