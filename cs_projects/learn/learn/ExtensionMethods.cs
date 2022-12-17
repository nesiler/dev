namespace learn
{
    public static class ExtensionMethods
    {
        public static string GenerateSlug(this string str)
        {
            return str.Replace(" ", "-")
                .Replace("Ç", "c")
                .Replace("Ş", "s")
                .Replace("Ö", "o")
                .Replace("Ğ", "g")
                .Replace("Ü", "u")
                .ToLower();
        }
    }
}
