
public class PermissionTester {

    public static byte canRead = 0b0001;

    public static void main(String[] args) {
        Permission p1 = new Permission(false, false, false, false);
        Permission p2 = new Permission(true, false, false, false);
        Permission p3 = new Permission(false, true, false, false);
        Permission p4 = new Permission(false, false, true, false);
        Permission p5 = new Permission(false, false, false, true);
        Permission p6 = new Permission(true, true, true, true);
        System.out.println(p1.getPermission());
        System.out.println(p2.getPermission());
        System.out.println(p3.getPermission());
        System.out.println(p4.getPermission());
        System.out.println(p5.getPermission());
        System.out.println(p6.getPermission());
        System.out.println("===================");
        System.out.println((p1.getPermission() & 0b1111) == p1.getPermission());
        System.out.println((p2.getPermission() & canRead) == canRead);

        System.out.println((p2.getPermission() & 0b1111) == p2.getPermission());
        System.out.println((p3.getPermission() & 0b1011) == p3.getPermission());
        System.out.println((p4.getPermission() & 0b0010) == p4.getPermission());
        System.out.println((p5.getPermission() & canRead) == canRead);
        System.out.println((p6.getPermission() & 0b0001) == p6.getPermission());
        System.out.println((p6.getPermission() & 0b0001) == 0b0001);
        System.out.println((p6.getPermission() & canRead) == canRead);

        System.out.println("abc_bbb_dd".split("_")[0]);

    }

}
