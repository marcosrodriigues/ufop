package sd.tp2.produtor.problem;

import java.util.LinkedList;

public class Resource<S> {

    private LinkedList<S> registers;
    protected boolean finished;

    public Resource() {
        this.registers = new LinkedList<>();
        this.finished = false;
    }

    public synchronized void putRegister(S register) {
        this.registers.add(register);
        wakeUp();
    }

    protected synchronized void wakeUp() {
        this.notify();
    }

    public synchronized S getRegister() throws Exception {
        if (!this.registers.isEmpty()) return this.registers.removeFirst();
        if (!finished) suspend();
        return null;
    }

    protected synchronized void suspend() throws Exception {
        wait();
    }

    public int getNumOfRegisters() {
        return this.registers.size();
    }

    public synchronized void setFinished() {
        this.finished = true;
        this.notifyAll();
    }

    public boolean isFinished() {
        return this.finished;
    }


}
