#include "expect_tokens.hpp"
#include "terminalpp/terminal.hpp"
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class terminal_read_cursor_test : public CppUnit::TestFixture
{
public :
    CPPUNIT_TEST_SUITE(terminal_read_cursor_test);
        CPPUNIT_TEST(up_command_yields_vk_up);
        CPPUNIT_TEST(down_command_yields_vk_down);
        CPPUNIT_TEST(right_command_yields_vk_right);
        CPPUNIT_TEST(left_command_yields_vk_left);

        CPPUNIT_TEST(direction_meta_command_yields_meta_vk);
        CPPUNIT_TEST(direction_commands_with_repeat_count_yield_vk_with_repeat_count);

        CPPUNIT_TEST(home_command_yields_vk_home);
        CPPUNIT_TEST(alternative_home_command_yields_vk_home);
        CPPUNIT_TEST(ins_command_yields_vk_ins);
        CPPUNIT_TEST(del_command_yields_vk_del);
        CPPUNIT_TEST(end_command_yields_vk_end);
        CPPUNIT_TEST(pgup_command_yields_vk_pgup);
        CPPUNIT_TEST(pgdn_command_yields_vk_pgdn);

        CPPUNIT_TEST(cursor_meta_command_yields_meta_vk);

        CPPUNIT_TEST(up_ss3_yields_vk_up);
        CPPUNIT_TEST(down_ss3_yields_vk_down);
        CPPUNIT_TEST(right_ss3_yields_vk_right);
        CPPUNIT_TEST(left_ss3_yields_vk_left);
        CPPUNIT_TEST(home_ss3_yields_vk_home);
        CPPUNIT_TEST(end_ss3_yields_vk_end);

        CPPUNIT_TEST(cursor_meta_ss3_yields_meta_vk);

        CPPUNIT_TEST(tab_key_yields_vk_tab);
        CPPUNIT_TEST(tab_command_yields_vk_tab);
        CPPUNIT_TEST(tab_ss3_yields_vk_tab);
        CPPUNIT_TEST(reverse_tab_command_yields_vk_reverse_tab);

        CPPUNIT_TEST(tab_command_with_repeat_count_yields_vk_with_repeat_count);
        CPPUNIT_TEST(reverse_tab_command_with_repeat_count_yields_vk_with_repeat_count);

        CPPUNIT_TEST(tab_meta_commands_yield_meta_vk);

        CPPUNIT_TEST(crlf_yields_vk_enter);
        CPPUNIT_TEST(crnul_yields_vk_enter);
        CPPUNIT_TEST(cr_then_nul_yields_enter_only);
        CPPUNIT_TEST(lfcr_yields_vk_enter);
        CPPUNIT_TEST(lf_yields_vk_enter);
        CPPUNIT_TEST(lflf_yields_two_vk_enters);
        CPPUNIT_TEST(enter_ss3_yields_vk_end);
    CPPUNIT_TEST_SUITE_END();

private :
    void up_command_yields_vk_up();
    void down_command_yields_vk_down();
    void right_command_yields_vk_right();
    void left_command_yields_vk_left();

    void direction_commands_with_repeat_count_yield_vk_with_repeat_count();
    void direction_meta_command_yields_meta_vk();

    void home_command_yields_vk_home();
    void alternative_home_command_yields_vk_home();
    void ins_command_yields_vk_ins();
    void del_command_yields_vk_del();
    void end_command_yields_vk_end();
    void pgup_command_yields_vk_pgup();
    void pgdn_command_yields_vk_pgdn();

    void cursor_meta_command_yields_meta_vk();

    void up_ss3_yields_vk_up();
    void down_ss3_yields_vk_down();
    void right_ss3_yields_vk_right();
    void left_ss3_yields_vk_left();
    void home_ss3_yields_vk_home();
    void end_ss3_yields_vk_end();

    void cursor_meta_ss3_yields_meta_vk();

    void tab_key_yields_vk_tab();
    void tab_command_yields_vk_tab();
    void tab_ss3_yields_vk_tab();
    void reverse_tab_command_yields_vk_reverse_tab();

    void tab_meta_commands_yield_meta_vk();

    void tab_command_with_repeat_count_yields_vk_with_repeat_count();
    void reverse_tab_command_with_repeat_count_yields_vk_with_repeat_count();

    void crlf_yields_vk_enter();
    void crnul_yields_vk_enter();
    void cr_then_nul_yields_enter_only();
    void lfcr_yields_vk_enter();
    void lf_yields_vk_enter();
    void lflf_yields_two_vk_enters();
    void enter_ss3_yields_vk_end();
};

CPPUNIT_TEST_SUITE_REGISTRATION(terminal_read_cursor_test);

void terminal_read_cursor_test::up_command_yields_vk_up()
{
    expect_token(
        "\x1B[A",
        terminalpp::virtual_key {
            terminalpp::vk::cursor_up,
            terminalpp::vk_modifier::none,
            1,
            terminalpp::ansi::control_sequence{'[', 'A', false, { "" }}
        });
}

void terminal_read_cursor_test::down_command_yields_vk_down()
{
    expect_token(
        "\x1B[B",
        terminalpp::virtual_key {
            terminalpp::vk::cursor_down,
            terminalpp::vk_modifier::none,
            1,
            terminalpp::ansi::control_sequence{'[', 'B', false, { "" }}
        });
}

void terminal_read_cursor_test::right_command_yields_vk_right()
{
    expect_token(
        "\x1B[C",
        terminalpp::virtual_key {
            terminalpp::vk::cursor_right,
            terminalpp::vk_modifier::none,
            1,
            terminalpp::ansi::control_sequence{'[', 'C', false, { "" }}
        });
}

void terminal_read_cursor_test::left_command_yields_vk_left()
{
    expect_token(
        "\x1B[D",
        terminalpp::virtual_key {
            terminalpp::vk::cursor_left,
            terminalpp::vk_modifier::none,
            1,
            terminalpp::ansi::control_sequence{'[', 'D', false, { "" }}
        });
}

void terminal_read_cursor_test::direction_commands_with_repeat_count_yield_vk_with_repeat_count()
{
    expect_token(
        "\x1B[1;A",
        terminalpp::virtual_key {
            terminalpp::vk::cursor_up,
            terminalpp::vk_modifier::none,
            1,
            terminalpp::ansi::control_sequence{'[', 'A', false, { "1" }}
        });

    expect_token(
        "\x1B[2;B",
        terminalpp::virtual_key {
            terminalpp::vk::cursor_down,
            terminalpp::vk_modifier::none,
            2,
            terminalpp::ansi::control_sequence{'[', 'B', false, { "2" }}
        });

    expect_token(
        "\x1B[3;C",
        terminalpp::virtual_key {
            terminalpp::vk::cursor_right,
            terminalpp::vk_modifier::none,
            3,
            terminalpp::ansi::control_sequence{'[', 'C', false, { "3" }}
        });

    expect_token(
        "\x1B[4;D",
        terminalpp::virtual_key {
            terminalpp::vk::cursor_left,
            terminalpp::vk_modifier::none,
            4,
            terminalpp::ansi::control_sequence{'[', 'D', false, { "4" }}
        });
}

void terminal_read_cursor_test::direction_meta_command_yields_meta_vk()
{
    expect_token(
        "\x1B\x1B[A",
        terminalpp::virtual_key {
            terminalpp::vk::cursor_up,
            terminalpp::vk_modifier::meta,
            1,
            terminalpp::ansi::control_sequence{'[', 'A', true, { "" }}
        });

    expect_token(
        "\x1B\x1B[B",
        terminalpp::virtual_key {
            terminalpp::vk::cursor_down,
            terminalpp::vk_modifier::meta,
            1,
            terminalpp::ansi::control_sequence{'[', 'B', true, { "" }}
        });

    expect_token(
        "\x1B\x1B[C",
        terminalpp::virtual_key {
            terminalpp::vk::cursor_right,
            terminalpp::vk_modifier::meta,
            1,
            terminalpp::ansi::control_sequence{'[', 'C', true, { "" }}
        });

    expect_token(
        "\x1B\x1B[D",
        terminalpp::virtual_key {
            terminalpp::vk::cursor_left,
            terminalpp::vk_modifier::meta,
            1,
            terminalpp::ansi::control_sequence{'[', 'D', false, { "" }}
        });
}

void terminal_read_cursor_test::home_command_yields_vk_home()
{
    expect_token(
        "\x1B[1~",
        terminalpp::virtual_key {
            terminalpp::vk::home,
            terminalpp::vk_modifier::none,
            1,
            terminalpp::ansi::control_sequence{'[', '~', false, { "1" }}
        });
}

void terminal_read_cursor_test::alternative_home_command_yields_vk_home()
{
    expect_token(
        "\x1B[H",
        terminalpp::virtual_key {
            terminalpp::vk::home,
            terminalpp::vk_modifier::none,
            1,
            terminalpp::ansi::control_sequence{'[', 'H', false, {}}
        });
}

void terminal_read_cursor_test::ins_command_yields_vk_ins()
{
    expect_token(
        "\x1B[2~",
        terminalpp::virtual_key {
            terminalpp::vk::ins,
            terminalpp::vk_modifier::none,
            1,
            terminalpp::ansi::control_sequence{'[', '~', false, { "2" }}
        });
}

void terminal_read_cursor_test::del_command_yields_vk_del()
{
    expect_token(
        "\x1B[3~",
        terminalpp::virtual_key {
            terminalpp::vk::del,
            terminalpp::vk_modifier::none,
            1,
            terminalpp::ansi::control_sequence{'[', '~', false, { "3" }}
        });
}

void terminal_read_cursor_test::end_command_yields_vk_end()
{
    expect_token(
        "\x1B[4~",
        terminalpp::virtual_key {
            terminalpp::vk::end,
            terminalpp::vk_modifier::none,
            1,
            terminalpp::ansi::control_sequence{'[', '~', false, { "4" }}
        });
}

void terminal_read_cursor_test::pgup_command_yields_vk_pgup()
{
    expect_token(
        "\x1B[5~",
        terminalpp::virtual_key {
            terminalpp::vk::pgup,
            terminalpp::vk_modifier::none,
            1,
            terminalpp::ansi::control_sequence{'[', '~', false, { "5" }}
        });
}

void terminal_read_cursor_test::pgdn_command_yields_vk_pgdn()
{
    expect_token(
        "\x1B[6~",
        terminalpp::virtual_key {
            terminalpp::vk::pgdn,
            terminalpp::vk_modifier::none,
            1,
            terminalpp::ansi::control_sequence{'[', '~', false, { "6" }}
        });
}

void terminal_read_cursor_test::cursor_meta_command_yields_meta_vk()
{
    expect_token(
        "\x1B\x1B[1~",
        terminalpp::virtual_key {
            terminalpp::vk::home,
            terminalpp::vk_modifier::meta,
            1,
            terminalpp::ansi::control_sequence{'[', '~', true, { "1" }}
        });

    expect_token(
        "\x1B\x1B[H",
        terminalpp::virtual_key {
            terminalpp::vk::home,
            terminalpp::vk_modifier::meta,
            1,
            terminalpp::ansi::control_sequence{'[', 'H', true, {}}
        });

    expect_token(
        "\x1B\x1B[2~",
        terminalpp::virtual_key {
            terminalpp::vk::ins,
            terminalpp::vk_modifier::meta,
            1,
            terminalpp::ansi::control_sequence{'[', '~', true, { "2" }}
        });

    expect_token(
        "\x1B\x1B[3~",
        terminalpp::virtual_key {
            terminalpp::vk::del,
            terminalpp::vk_modifier::meta,
            1,
            terminalpp::ansi::control_sequence{'[', '~', true, { "3" }}
        });

    expect_token(
        "\x1B\x1B[4~",
        terminalpp::virtual_key {
            terminalpp::vk::end,
            terminalpp::vk_modifier::meta,
            1,
            terminalpp::ansi::control_sequence{'[', '~', true, { "4" }}
        });

    expect_token(
        "\x1B\x1B[5~",
        terminalpp::virtual_key {
            terminalpp::vk::pgup,
            terminalpp::vk_modifier::meta,
            1,
            terminalpp::ansi::control_sequence{'[', '~', true, { "5" }}
        });

    expect_token(
        "\x1B\x1B[6~",
        terminalpp::virtual_key {
            terminalpp::vk::pgdn,
            terminalpp::vk_modifier::meta,
            1,
            terminalpp::ansi::control_sequence{'[', '~', true, { "6" }}
        });
}

void terminal_read_cursor_test::up_ss3_yields_vk_up()
{
    expect_token(
        "\x1BOA",
        terminalpp::virtual_key {
            terminalpp::vk::cursor_up,
            terminalpp::vk_modifier::none,
            1,
            terminalpp::ansi::control_sequence{'O', 'A', false, { "" }}
        });
}

void terminal_read_cursor_test::down_ss3_yields_vk_down()
{
    expect_token(
        "\x1BOB",
        terminalpp::virtual_key {
            terminalpp::vk::cursor_down,
            terminalpp::vk_modifier::none,
            1,
            terminalpp::ansi::control_sequence{'O', 'B', false, { "" }}
        });
}

void terminal_read_cursor_test::right_ss3_yields_vk_right()
{
    expect_token(
        "\x1BOC",
        terminalpp::virtual_key {
            terminalpp::vk::cursor_right,
            terminalpp::vk_modifier::none,
            1,
            terminalpp::ansi::control_sequence{'O', 'C', false, { "" }}
        });
}

void terminal_read_cursor_test::left_ss3_yields_vk_left()
{
    expect_token(
        "\x1BOD",
        terminalpp::virtual_key {
            terminalpp::vk::cursor_left,
            terminalpp::vk_modifier::none,
            1,
            terminalpp::ansi::control_sequence{'O', 'D', false, { "" }}
        });
}

void terminal_read_cursor_test::home_ss3_yields_vk_home()
{
    expect_token(
        "\x1BOH",
        terminalpp::virtual_key {
            terminalpp::vk::home,
            terminalpp::vk_modifier::none,
            1,
            terminalpp::ansi::control_sequence{'O', 'H', false, { "" }}
        });
}

void terminal_read_cursor_test::end_ss3_yields_vk_end()
{
    expect_token(
        "\x1BOF",
        terminalpp::virtual_key {
            terminalpp::vk::end,
            terminalpp::vk_modifier::none,
            1,
            terminalpp::ansi::control_sequence{'O', 'F', false, { "" }}
        });
}

void terminal_read_cursor_test::cursor_meta_ss3_yields_meta_vk()
{
    expect_token(
        "\x1B\x1BOA",
        terminalpp::virtual_key {
            terminalpp::vk::cursor_up,
            terminalpp::vk_modifier::meta,
            1,
            terminalpp::ansi::control_sequence{'O', 'A', true, { "" }}
        });

    expect_token(
        "\x1B\x1BOB",
        terminalpp::virtual_key {
            terminalpp::vk::cursor_down,
            terminalpp::vk_modifier::meta,
            1,
            terminalpp::ansi::control_sequence{'O', 'B', true, { "" }}
        });

    expect_token(
        "\x1B\x1BOC",
        terminalpp::virtual_key {
            terminalpp::vk::cursor_right,
            terminalpp::vk_modifier::meta,
            1,
            terminalpp::ansi::control_sequence{'O', 'C', true, { "" }}
        });

    expect_token(
        "\x1B\x1BOD",
        terminalpp::virtual_key {
            terminalpp::vk::cursor_left,
            terminalpp::vk_modifier::meta,
            1,
            terminalpp::ansi::control_sequence{'O', 'D', true, { "" }}
        });

    expect_token(
        "\x1B\x1BOH",
        terminalpp::virtual_key {
            terminalpp::vk::home,
            terminalpp::vk_modifier::meta,
            1,
            terminalpp::ansi::control_sequence{'O', 'H', true, { "" }}
        });

    expect_token(
        "\x1B\x1BOF",
        terminalpp::virtual_key {
            terminalpp::vk::end,
            terminalpp::vk_modifier::meta,
            1,
            terminalpp::ansi::control_sequence{'O', 'F', true, { "" }}
        });
}

void terminal_read_cursor_test::tab_key_yields_vk_tab()
{
    expect_token(
        "\t",
        terminalpp::virtual_key {
            terminalpp::vk::ht,
            terminalpp::vk_modifier::none,
            1,
            '\t'
        });
}

void terminal_read_cursor_test::tab_command_yields_vk_tab()
{
    expect_token(
        "\x1B[I",
        terminalpp::virtual_key {
            terminalpp::vk::ht,
            terminalpp::vk_modifier::none,
            1,
            terminalpp::ansi::control_sequence{'[', 'I', false, { "" }}
        });
}

void terminal_read_cursor_test::tab_ss3_yields_vk_tab()
{
    expect_token(
        "\x1BOI",
        terminalpp::virtual_key {
            terminalpp::vk::ht,
            terminalpp::vk_modifier::none,
            1,
            terminalpp::ansi::control_sequence{'O', 'I', false, { "" }}
        });
}

void terminal_read_cursor_test::reverse_tab_command_yields_vk_reverse_tab()
{
    expect_token(
        "\x1B[Z",
        terminalpp::virtual_key {
            terminalpp::vk::bt,
            terminalpp::vk_modifier::none,
            1,
            terminalpp::ansi::control_sequence{'[', 'Z', false, { "" }}
        });
}

void terminal_read_cursor_test::tab_meta_commands_yield_meta_vk()
{
    expect_token(
        "\x1B\x1B[I",
        terminalpp::virtual_key {
            terminalpp::vk::ht,
            terminalpp::vk_modifier::meta,
            1,
            terminalpp::ansi::control_sequence{'[', 'I', true, { "" }}
        });

    expect_token(
        "\x1B\x1BOI",
        terminalpp::virtual_key {
            terminalpp::vk::ht,
            terminalpp::vk_modifier::meta,
            1,
            terminalpp::ansi::control_sequence{'O', 'I', true, { "" }}
        });

    expect_token(
        "\x1B\x1B[Z",
        terminalpp::virtual_key {
            terminalpp::vk::bt,
            terminalpp::vk_modifier::meta,
            1,
            terminalpp::ansi::control_sequence{'[', 'Z', true, { "" }}
        });
}

void terminal_read_cursor_test::tab_command_with_repeat_count_yields_vk_with_repeat_count()
{
    expect_token(
        "\x1B[7I",
        terminalpp::virtual_key {
            terminalpp::vk::ht,
            terminalpp::vk_modifier::none,
            7,
            terminalpp::ansi::control_sequence{'[', 'I', false, { "7" }}
        });
}

void terminal_read_cursor_test::reverse_tab_command_with_repeat_count_yields_vk_with_repeat_count()
{
    expect_token(
        "\x1B[10Z",
        terminalpp::virtual_key {
            terminalpp::vk::bt,
            terminalpp::vk_modifier::none,
            10,
            terminalpp::ansi::control_sequence{'[', 'I', false, { "10" }}
        });
}

void terminal_read_cursor_test::crlf_yields_vk_enter()
{
    expect_tokens(
        "\r\na",
        {
            { terminalpp::virtual_key {
                terminalpp::vk::enter,
                terminalpp::vk_modifier::none,
                1,
                '\n'
            }},
            { terminalpp::virtual_key {
                terminalpp::vk::lowercase_a,
                terminalpp::vk_modifier::none,
                1,
                'a'
            }}
        });
}

void terminal_read_cursor_test::crnul_yields_vk_enter()
{
    std::string text("\r\0", 2);

    expect_token(
        text,
        terminalpp::virtual_key {
            terminalpp::vk::enter,
            terminalpp::vk_modifier::none,
            1,
            '\n'
        });
}

void terminal_read_cursor_test::cr_then_nul_yields_enter_only()
{
    terminalpp::terminal terminal;

    auto expected_after_cr = terminalpp::virtual_key {
        terminalpp::vk::enter,
        terminalpp::vk_modifier::none,
        1,
        '\n'
    };

    auto actual_after_cr = terminal.read("\r");
    CPPUNIT_ASSERT_EQUAL(size_t{1}, actual_after_cr.size());
    CPPUNIT_ASSERT_EQUAL(
        expected_after_cr,
        boost::get<terminalpp::virtual_key>(actual_after_cr[0]));

    auto actual_after_nul = terminal.read(std::string("\0", 1));
    CPPUNIT_ASSERT(actual_after_nul.empty());
}

void terminal_read_cursor_test::lfcr_yields_vk_enter()
{
    expect_token(
        "\n\r",
        terminalpp::virtual_key {
            terminalpp::vk::enter,
            terminalpp::vk_modifier::none,
            1,
            '\n'
        });
}

void terminal_read_cursor_test::lf_yields_vk_enter()
{
    expect_tokens(
        "\na",
        {
            { terminalpp::virtual_key {
                terminalpp::vk::enter,
                terminalpp::vk_modifier::none,
                1,
                '\n'
            }},
            { terminalpp::virtual_key {
                terminalpp::vk::lowercase_a,
                terminalpp::vk_modifier::none,
                1,
                'a'
            }}
        });
}

void terminal_read_cursor_test::lflf_yields_two_vk_enters()
{
    expect_tokens(
        "\n\n",
        {
            { terminalpp::virtual_key {
                terminalpp::vk::enter,
                terminalpp::vk_modifier::none,
                1,
                '\n'
            }},
            { terminalpp::virtual_key {
                terminalpp::vk::enter,
                terminalpp::vk_modifier::none,
                1,
                '\n'
            }}
        });
}

void terminal_read_cursor_test::enter_ss3_yields_vk_end()
{
    expect_token(
        "\x1BOM",
        terminalpp::virtual_key {
            terminalpp::vk::enter,
            terminalpp::vk_modifier::none,
            1,
            terminalpp::ansi::control_sequence{ 'O', 'M', false, { "" } }
        });
}
