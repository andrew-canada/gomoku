
public class Permission {

    private boolean canRead;
    private boolean canWrite;
    private boolean canDelete;
    private boolean canList;

    public Permission(boolean canList, boolean canDelete, boolean canWrite, boolean canRead) {
        this.canRead = canRead;
        this.canWrite = canWrite;
        this.canDelete = canDelete;
        this.canList = canList;
    }

    public boolean isCanRead() {
        return canRead;
    }

    public void setCanRead(boolean canRead) {
        this.canRead = canRead;
    }

    public boolean isCanWrite() {
        return canWrite;
    }

    public void setCanWrite(boolean canWrite) {
        this.canWrite = canWrite;
    }

    public boolean isCanDelete() {
        return canDelete;
    }

    public void setCanDelete(boolean canDelete) {
        this.canDelete = canDelete;
    }

    public boolean isCanList() {
        return canList;
    }

    public void setCanList(boolean canList) {
        this.canList = canList;
    }

    public byte getPermission() {
        return (byte) ((canList ? 1 : 0) << 3 | (canDelete ? 1 : 0) << 2 | (canWrite ? 1 : 0) << 1
                | (canRead ? 1 : 0));
    }

}
