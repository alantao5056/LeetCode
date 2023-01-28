import java.util.TreeSet;

class Test {
  public static void main(String[] args) {
    TreeSet<Foo> ts = new TreeSet<>();
    Foo f1 = new Foo(1, 2);
    Foo f2 = new Foo(1, 2);
    ts.add(f1);
    ts.add(f2);
    System.out.println(ts.size());
  }

  static class Foo implements Comparable<Foo> {
    public int a;
    public int b;

    public Foo(int a, int b) {
      this.a = a;
      this.b = b;
    }

    @Override
    public int compareTo(Foo f) {
      return this.a - f.a;
    }
  }
}