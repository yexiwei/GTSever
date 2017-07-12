#ifndef GT_NET_MULITYTHREADS_H_
#define GT_NET_MULITYTHREADS_H_

#include <vector>
#include <atomic>
#include <thread>
namespace GT {
    namespace NET {
        struct Thread_Tuple {
            std::thread this_thread_;
            std::atomic<bool> end_thread_;
            Thread_Tuple::Thread_Tuple(std::thread t, std::atomic<bool> b) :this_thread_(std::move(t)), end_thread_(std::move(b.load())){}
        };

        class GT_ThreadPool
        {
        public:
            GT_ThreadPool();
            ~GT_ThreadPool();

        public:
            void Start(size_t poolsize, std::function<void()>);
            void Stop();

        private:
            void LongTimeWorker_(std::function<void()>, std::atomic<bool>);

        private:
            std::vector<Thread_Tuple> workpool_;
        };
    }
}


#endif // GT_NET_MULITYTHREADS_H_