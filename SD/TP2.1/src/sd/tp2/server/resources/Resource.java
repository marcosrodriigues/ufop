package sd.tp2.server.resources;

import java.util.concurrent.ConcurrentLinkedQueue;

public class Resource<S> {

    private ConcurrentLinkedQueue<S> register;
    private boolean finished, serverFinished;

    public Resource() {
        this.register = new ConcurrentLinkedQueue<>();
        finished = false;
        serverFinished = false;
    }

    public void putRegister(S register) {
        this.register.offer(register);
        wakeup();
    }

    public S getRegister() throws Exception {
        if (!this.register.isEmpty())
            return this.register.poll();
        else {
            if (!finished)
                suspend();
            return null;
        }
    }

    private synchronized void suspend() throws Exception {
        wait();
    }

    private synchronized void wakeup() {
        notify();
    }

    public int getNumOfRegister() {
        return this.register.size();
    }

    public synchronized void setFinished() {
        this.finished = true;
        notifyAll();
    }

    public boolean isFinished() {
        return this.finished;
    }

    public boolean isStopped() {
        return this.serverFinished;
    }

    public synchronized void stopServer() {
        this.serverFinished = false;
    }
}
