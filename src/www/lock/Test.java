package www.lock;

import org.jetbrains.annotations.NotNull;

import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;

class Mutex implements Lock {
    private Sync sync = new Sync();
    // ...............................
    static class Sync extends AbstractMethodError {
        protected void tryAcquire(int arg) {
            if (arg != 1) {
                throw new RuntimeException("信号量不为1");
            }
//            if(compareAndSetState(0,1)){
//                // 当前线程成功获取
//                setExclusiveOwnerThread(Thread.currentThread());
//                return true;
//            }
        }
    }

    @Override
    public void lock() {
        
    }

    @Override
    public void lockInterruptibly() throws InterruptedException {

    }

    @Override
    public boolean tryLock() {
        return false;
    }

    @Override
    public boolean tryLock(long time, @NotNull TimeUnit unit) throws InterruptedException {
        return false;
    }

    @Override
    public void unlock() {

    }

    @NotNull
    @Override
    public Condition newCondition() {
        return null;
    }

}
