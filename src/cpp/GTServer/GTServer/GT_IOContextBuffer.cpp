#include "GT_IOContextBuffer.h"

namespace GT {

	namespace NET {

		GT_IOContextBuffer::GT_IOContextBuffer(size_t len) {
			Internal = InternalHigh = 0;
			Offset = OffsetHigh = 0;
			hEvent = NULL;
			io_buffer_size_ = len;
			io_wsa_buf_.buf = io_buffer_;
			io_wsa_buf_.len = io_buffer_size_;
			event_type_ = IO_EVENT_NULL;
		}

		GT_IOContextBuffer::~GT_IOContextBuffer() {
			delete[] io_buffer_;
		}

		bool GT_IOContextBuffer::AllocateIOBuffer() {
			io_buffer_ = new char[io_buffer_size_];
			return io_buffer_ == nullptr ? false : true;
		}

		void GT_IOContextBuffer::SetIOBufferSocket(SOCKET& s) {
			io_socket_ = s;
		}

		void GT_IOContextBuffer::SetIOBufferEventType(IO_EVENT_TYPE type) {
			event_type_ = type;
		}

		void GT_IOContextBuffer::ResetBuffer() {
			memset(io_buffer_, 0, io_buffer_size_);
		}
	}
}