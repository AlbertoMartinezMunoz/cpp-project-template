import pytest

# content of test_class.py
class TestClass:
    @pytest.fixture(autouse=True)
    def setup_and_teardown(self):
        print("\nSetting up resources...")
        yield
        print("\nTearing down resources...")

    def test_one(self):
        print("\nRunning test one...")
        x = "this"
        assert "j" in x

    def test_sum(self):
        print("\nRunning test sum...")
        assert (0.1 + 0.2) == pytest.approx(0.3)
